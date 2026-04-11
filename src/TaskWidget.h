#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace month_flow
{
	class TaskWidget: public QWidget
	{
		Q_OBJECT

	public:
		explicit TaskWidget(const QString& name, QWidget* parent = nullptr);
		~TaskWidget() override;

	signals:
		void ButtonRemoveClick();

	private:
		void CreateUi();

		QLabel* m_labelName = nullptr;
		QLabel* m_labelStatus = nullptr;
		QPushButton* m_buttonRemove = nullptr;
	};
}
