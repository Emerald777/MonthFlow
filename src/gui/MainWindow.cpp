#include "MainWindow.h"

#include <QStackedWidget>

#include "ControlWidget.h"
#include "NewTaskDialog.h"

month_flow::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("MonthFlow - Task Tracker");
	resize(1024, 768);

	CreateUi();
	CreateConnections();
}

void month_flow::MainWindow::CreateUi()
{
	m_controlWidget = new ControlWidget(this);
	m_newTaskDialog = new NewTaskDialog(this);

	m_stackWidget = new QStackedWidget(this);
	m_stackWidget->addWidget(m_controlWidget);
	m_stackWidget->addWidget(m_newTaskDialog);

	SelectPage(StackedPage::Control);

	setCentralWidget(m_stackWidget);
}

void month_flow::MainWindow::CreateConnections()
{
	QObject::connect(m_controlWidget, &ControlWidget::CreateTaskClicked, this,
		[this](){ SelectPage(StackedPage::NewTaskDialog); });

	QObject::connect(m_newTaskDialog, &NewTaskDialog::FinishClicked, this,
		[this](){ SelectPage(StackedPage::Control); });
}

void month_flow::MainWindow::SelectPage(StackedPage page)
{
	m_stackWidget->setCurrentIndex(ToInt(page));
}
