#pragma once

#include <QWidget>
#include "TaskData.h"

#include "ui_NewTaskDialog.h"

class QDateEdit;
class QSpinBox;

namespace month_flow
{
	class NewTaskDialog: public QWidget
	{
		Q_OBJECT

	public:
		explicit NewTaskDialog(QWidget* parent = nullptr);
		~NewTaskDialog() override;

	signals:
		void FinishClicked(const month_flow::data::Task& data);

	private slots:
		void OnButtonFinishClicked();
		void OnRadioButtonSelected();

	private:
		void CreateGui();
		void UpdateGui();

		bool IsSingleTaskChosen() const;

		Ui::NewTaskDialog m_ui;

		QDateEdit* m_dateEditSingle = nullptr;
		QSpinBox* m_spinPeriodic = nullptr;
	};
}
