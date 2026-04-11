#include "TaskWidget.h"

#include <QBoxLayout>

namespace
{
	constexpr int ContentMargin = 2;
}

month_flow::TaskWidget::TaskWidget(const QString& name, QWidget* parent) : QWidget(parent)
{
	CreateUi();

	m_labelName->setText(name);
	QObject::connect(m_buttonRemove, &QPushButton::clicked, this, &TaskWidget::ButtonRemoveClick);
}

month_flow::TaskWidget::~TaskWidget()
{
}

void month_flow::TaskWidget::CreateUi()
{
	const auto mainLayout = new QHBoxLayout();
	mainLayout->setContentsMargins(ContentMargin, ContentMargin, ContentMargin, ContentMargin);

	m_labelName = new QLabel("Task");
	m_labelStatus = new QLabel("Active");
	m_buttonRemove = new QPushButton("X");
	m_buttonRemove->setFixedSize(20, 20);

	m_labelName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_labelStatus->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

	mainLayout->addWidget(m_labelName);
	mainLayout->addWidget(m_labelStatus);
	mainLayout->addWidget(m_buttonRemove);

	setLayout(mainLayout);
}
