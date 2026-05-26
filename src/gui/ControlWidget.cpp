#include "ControlWidget.h"

month_flow::ControlWidget::ControlWidget(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	QObject::connect(m_ui.buttonAddTask, &QPushButton::clicked, this, &ControlWidget::OnButtonAddClicked);
}

month_flow::ControlWidget::~ControlWidget()
{
}

void month_flow::ControlWidget::CreateTask()
{
	const auto newPointWidget = new TaskWidget("New Test task #1", this);
	QObject::connect(newPointWidget, &TaskWidget::ButtonRemoveClick, this, &ControlWidget::OnButtonRemoveClick);
	m_taskWidgets.push_back(newPointWidget);
	m_ui.vLayoutTasks->addWidget(newPointWidget);
}

void month_flow::ControlWidget::OnButtonAddClicked()
{
	emit CreateTaskClicked();
}

void month_flow::ControlWidget::OnButtonRemoveClick()
{
	const auto it = std::find(m_taskWidgets.begin(), m_taskWidgets.end(), static_cast<TaskWidget*>(sender()));

	if (it != m_taskWidgets.end())
	{
		m_taskWidgets.erase(it);
		sender()->deleteLater();
	}
}
