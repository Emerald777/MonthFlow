#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>

#include "ExpanderWidget.h"
#include "DeadlineStatus.h"
#include "TaskData.h"

namespace month_flow
{
	class TaskWidget: public QWidget
	{
		Q_OBJECT

	public:
		explicit TaskWidget(const QString& name, QWidget* parent = nullptr);
		~TaskWidget() override;

		void SetExpanded(bool isExpanded);
		void SetDeadlineStatus(DeadlineStatus newStatus);
		void SetDeadline(const VariantDeadline& newDeadline);

	signals:
		void ButtonRemoveClick();

	protected:
		bool eventFilter(QObject* watched, QEvent* event) override;

	private:
		void CreateUi();
		QHBoxLayout* CreateBaseLineLayout();
		QHBoxLayout* CreateCommentLineLayout();
		QHBoxLayout* CreateButtonsLineLayout();

		ExpanderWidget* m_expander = nullptr;

		QLabel* m_labelName = nullptr;
		QLabel* m_labelDeadlineDay = nullptr;
		QLabel* m_labelDaysLeft = nullptr;

		QFrame* m_commentPanel = nullptr;
		QLabel* m_labelComment = nullptr;

		QPushButton* m_buttonComplete = nullptr;
		QPushButton* m_buttonRemove = nullptr;
	};
}
