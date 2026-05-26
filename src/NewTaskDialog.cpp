#include "NewTaskDialog.h"

month_flow::NewTaskDialog::NewTaskDialog(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	QObject::connect(m_ui.buttonCreateTask, &QPushButton::clicked, this, &NewTaskDialog::OnButtonFinishClicked);
}

month_flow::NewTaskDialog::~NewTaskDialog()
{
}

void month_flow::NewTaskDialog::OnButtonFinishClicked()
{
	emit FinishClicked();
}
