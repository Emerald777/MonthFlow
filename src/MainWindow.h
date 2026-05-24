#pragma once

#include <QMainWindow>

namespace month_flow
{
	class MainWindow: public QMainWindow
	{
	public:
		MainWindow(QWidget* parent = nullptr);

	private:
		void CreateUi();
	};
}
