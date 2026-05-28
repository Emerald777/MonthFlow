#pragma once

#include <QWidget>

#include "ui_ProfileDialog.h"

namespace month_flow
{
	class ProfileDialog: public QWidget
	{
		Q_OBJECT

	public:
		explicit ProfileDialog(QWidget* parent = nullptr);
		~ProfileDialog() override;

	signals:
		void ProceedClicked();

	private slots:
		void OnRadioButtonSelected();

	private:
		void UpdateGui();

		Ui::ProfileDialog m_ui;
	};
}
