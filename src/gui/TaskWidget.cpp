#include "TaskWidget.h"

#include <qcoreevent.h>

#include "Styles.h"

namespace
{
	constexpr int ContentMargin = 2;

	void SetLayoutMargins(QLayout* layout)
	{
		layout->setContentsMargins(ContentMargin, ContentMargin, ContentMargin, ContentMargin);
	}
}

month_flow::TaskWidget::TaskWidget(const QString& name, QWidget* parent) : QWidget(parent)
{
	CreateUi();

	SetDeadlineStatus(DeadlineStatus::Far); // TODO: setup deadline status after real check

	m_labelName->setText(name);
	QObject::connect(m_buttonRemove, &QPushButton::clicked, this, &TaskWidget::ButtonRemoveClick);

	m_labelName->installEventFilter(this);

	SetCommentExpanded(false);
}

month_flow::TaskWidget::~TaskWidget()
{
}

void month_flow::TaskWidget::SetCommentExpanded(bool isExpanded)
{
	m_commentPanel->setVisible(isExpanded);
	m_expander->SetExpanded(isExpanded);
}

void month_flow::TaskWidget::SetDeadlineStatus(DeadlineStatus newStatus)
{
	switch (newStatus)
	{
	case DeadlineStatus::Far:
		m_labelDaysLeft->setProperty("status", "far");
		break;

	case DeadlineStatus::Approaching:
		m_labelDaysLeft->setProperty("status", "approaching");
		break;
	}
}

bool month_flow::TaskWidget::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == m_labelName && event->type() == QEvent::MouseButtonPress)
	{
		const bool isVisible = m_commentPanel->isVisible();
		SetCommentExpanded(!isVisible);
		return true;
	}
	return QWidget::eventFilter(watched, event);
}

void month_flow::TaskWidget::CreateUi()
{
	const auto mainLayout = new QVBoxLayout();
	mainLayout->addLayout(CreateBaseLineLayout());
	mainLayout->addLayout(CreateCommentLineLayout());
	setLayout(mainLayout);

	setStyleSheet(str::MainTaskWidgetStyle);
}

QHBoxLayout* month_flow::TaskWidget::CreateBaseLineLayout()
{
	const auto baseLineLayout = new QHBoxLayout();
	SetLayoutMargins(baseLineLayout);

	m_expander = new ExpanderWidget();

	m_labelName = new QLabel("Task");
	m_labelName->setObjectName("task");

	m_labelDeadlineDay = new QLabel("15");
	m_labelDeadlineDay->setAlignment(Qt::AlignCenter);
	m_labelDeadlineDay->setObjectName("deadline");

	m_labelDaysLeft = new QLabel("99");
	m_labelDaysLeft->setAlignment(Qt::AlignCenter);
	m_labelDaysLeft->setObjectName("left");

	m_buttonRemove = new QPushButton("X");
	m_buttonRemove->setFixedSize(20, 20);

	m_labelName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	baseLineLayout->addWidget(m_expander);
	baseLineLayout->addWidget(m_labelName);
	baseLineLayout->addWidget(m_labelDeadlineDay);
	baseLineLayout->addWidget(m_labelDaysLeft);
	baseLineLayout->addWidget(m_buttonRemove);
	return baseLineLayout;
}

QHBoxLayout* month_flow::TaskWidget::CreateCommentLineLayout()
{
	const auto commentLineLayout = new QHBoxLayout();
	const auto innerLayout = new QHBoxLayout();
	SetLayoutMargins(innerLayout);

	m_commentPanel = new QFrame();
	m_commentPanel->setLayout(innerLayout);

	const auto nodeLabel = new QLabel(m_commentPanel);
	nodeLabel->setPixmap(QPixmap(":/images/comment_node.png"));
	nodeLabel->setScaledContents(true);
	nodeLabel->setFixedSize(12, 12); // TODO: make proper size related to the font

	m_labelComment = new QLabel("Comment", m_commentPanel);
	m_labelComment->setObjectName("comment");
	m_labelComment->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	innerLayout->addWidget(nodeLabel);
	innerLayout->addWidget(m_labelComment);

	commentLineLayout->addWidget(m_commentPanel);

	return commentLineLayout;
}
