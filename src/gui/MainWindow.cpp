#include "MainWindow.h"

#include <QStackedWidget>

#include "TasksViewer.h"
#include "NewTaskDialog.h"
#include "ProfileDialog.h"

month_flow::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("MonthFlow - Task Tracker");
	resize(1024, 768);

	CreateUi();
	CreateConnections();
}

void month_flow::MainWindow::OnTaskCreated(const TaskData& taskData)
{
	SelectPage(StackedPage::TasksView);

	if (m_tasksViewer)
		m_tasksViewer->CreateTask(taskData);
}

void month_flow::MainWindow::CreateUi()
{
	m_profileDialog = new ProfileDialog(this);
	m_tasksViewer = new TasksViewer(this);
	m_newTaskDialog = new NewTaskDialog(this);

	m_stackWidget = new QStackedWidget(this);
	m_stackWidget->addWidget(m_profileDialog);
	m_stackWidget->addWidget(m_tasksViewer);
	m_stackWidget->addWidget(m_newTaskDialog);

	SelectPage(StackedPage::ProfileDialog);

	setCentralWidget(m_stackWidget);
}

void month_flow::MainWindow::CreateConnections()
{
	QObject::connect(m_profileDialog, &ProfileDialog::ProceedClicked, this, [this](){ SelectPage(StackedPage::TasksView); });

	QObject::connect(m_tasksViewer, &TasksViewer::CreateTaskClicked, this, [this](){ SelectPage(StackedPage::NewTaskDialog); });
	QObject::connect(m_tasksViewer, &TasksViewer::ChangeProfileClicked, this, [this](){ SelectPage(StackedPage::ProfileDialog); });

	QObject::connect(m_newTaskDialog, &NewTaskDialog::FinishClicked, this, &MainWindow::OnTaskCreated);
	QObject::connect(m_newTaskDialog, &NewTaskDialog::CancelClicked, this, [this](){ SelectPage(StackedPage::TasksView); });
}

void month_flow::MainWindow::SelectPage(StackedPage page)
{
	m_stackWidget->setCurrentIndex(ToInt(page));
}
