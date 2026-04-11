#include "MainWindow.h"

#include "CentralWidget.h"

month_flow::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("MonthFlow - Monthly Task Tracker");
	resize(1024, 768);

	const auto widget = new CentralWidget(this);
	setCentralWidget(widget);
}
