#include "MainWindow.h"

#include <QStackedWidget>

#include "ControlWidget.h"

month_flow::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("MonthFlow - Task Tracker");
	resize(1024, 768);

	CreateUi();
}

void month_flow::MainWindow::CreateUi()
{
	const auto controlWidget = new ControlWidget(this);

	const auto stackedWidget = new QStackedWidget(this);
	stackedWidget->addWidget(controlWidget);

	setCentralWidget(stackedWidget);
}
