#include <QApplication>
#include "gui/MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	app.setApplicationName("MonthFlow");
	app.setApplicationVersion("1.0.0");
	app.setOrganizationName("Emerald Ltd.");

	month_flow::MainWindow window;
	window.show();

	return app.exec();
}
