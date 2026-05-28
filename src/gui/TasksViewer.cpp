#include "TasksViewer.h"

month_flow::TasksViewer::TasksViewer(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	QObject::connect(m_ui.buttonAddTask, &QPushButton::clicked, this, &TasksViewer::OnButtonAddClicked);
	QObject::connect(m_ui.buttonProfile, &QPushButton::clicked, this, &TasksViewer::ChangeProfileClicked);
}

month_flow::TasksViewer::~TasksViewer()
{
}

void month_flow::TasksViewer::CreateTask(const TaskData& taskData)
{
	const auto newPointWidget = new TaskWidget(QString::fromStdString(taskData.name), this);
	newPointWidget->SetDeadline(taskData.deadline);
	QObject::connect(newPointWidget, &TaskWidget::ButtonRemoveClick, this, &TasksViewer::OnButtonRemoveClick);
	m_taskWidgets.push_back(newPointWidget);
	m_ui.vLayoutTasks->addWidget(newPointWidget);
}

void month_flow::TasksViewer::OnButtonAddClicked()
{
	emit CreateTaskClicked();
}

void month_flow::TasksViewer::OnButtonRemoveClick()
{
	const auto it = std::find(m_taskWidgets.begin(), m_taskWidgets.end(), static_cast<TaskWidget*>(sender()));

	if (it != m_taskWidgets.end())
	{
		m_taskWidgets.erase(it);
		sender()->deleteLater();
	}
}
