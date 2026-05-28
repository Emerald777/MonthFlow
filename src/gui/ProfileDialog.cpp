#include "ProfileDialog.h"

month_flow::ProfileDialog::ProfileDialog(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	QObject::connect(m_ui.buttonProceed, &QPushButton::clicked, this, &ProfileDialog::ProceedClicked);
	QObject::connect(m_ui.radioLocal, &QRadioButton::clicked, this, &ProfileDialog::OnRadioButtonSelected);
	QObject::connect(m_ui.radioRemote, &QRadioButton::clicked, this, &ProfileDialog::OnRadioButtonSelected);

	UpdateGui();
}

month_flow::ProfileDialog::~ProfileDialog()
{
}

void month_flow::ProfileDialog::OnRadioButtonSelected()
{
	UpdateGui();
}

void month_flow::ProfileDialog::UpdateGui()
{
	m_ui.editRemoteHost->setEnabled(m_ui.radioRemote->isChecked());
}
