#include "CentralWidget.h"

month_flow::CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	QObject::connect(m_ui.buttonAddTask, &QPushButton::clicked, this, &CentralWidget::OnButtonAddClicked);
}

month_flow::CentralWidget::~CentralWidget()
{
}

void month_flow::CentralWidget::OnButtonAddClicked()
{
	// TODO: add dialog

	const auto newPointWidget = new TaskWidget("New Test task #1", this);
	QObject::connect(newPointWidget, &TaskWidget::ButtonRemoveClick, this, &CentralWidget::OnButtonRemoveClick);
	m_taskWidgets.push_back(newPointWidget);
	m_ui.vLayoutTasks->addWidget(newPointWidget);
}

void month_flow::CentralWidget::OnButtonRemoveClick()
{
	const auto it = std::find(m_taskWidgets.begin(), m_taskWidgets.end(), static_cast<TaskWidget*>(sender()));

	if (it != m_taskWidgets.end())
	{
		m_taskWidgets.erase(it);
		sender()->deleteLater();
	}
}
