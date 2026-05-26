#include "NewTaskDialog.h"

#include <QHBoxLayout>
#include <QSpinBox>
#include <QDateEdit>

month_flow::NewTaskDialog::NewTaskDialog(QWidget* parent) : QWidget(parent)
{
	m_ui.setupUi(this);

	CreateGui();
	UpdateGui();

	QObject::connect(m_ui.buttonCreateTask, &QPushButton::clicked, this, &NewTaskDialog::OnButtonFinishClicked);
	QObject::connect(m_ui.radioSingleTask, &QRadioButton::clicked, this, &NewTaskDialog::OnRadioButtonSelected);
	QObject::connect(m_ui.radioPeriodicTask, &QRadioButton::clicked, this, &NewTaskDialog::OnRadioButtonSelected);
}

month_flow::NewTaskDialog::~NewTaskDialog()
{
}

void month_flow::NewTaskDialog::OnButtonFinishClicked()
{
	data::VariantDeadline newDeadline;
	if (IsSingleTaskChosen())
		newDeadline = m_dateEditSingle->date();
	else
		newDeadline = m_spinPeriodic->value();

	const data::Task taskData
	{
		.name = m_ui.editTaskName->text().toStdString(),
		.description = m_ui.editDescription->toPlainText().toStdString(),
		.deadline = std::move(newDeadline)
	};
	emit FinishClicked(taskData);
}

void month_flow::NewTaskDialog::OnRadioButtonSelected()
{
	UpdateGui();
}

void month_flow::NewTaskDialog::CreateGui()
{
	m_dateEditSingle = new QDateEdit();
	m_dateEditSingle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_spinPeriodic = new QSpinBox();
	m_spinPeriodic->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_spinPeriodic->setMinimum(1);
	m_spinPeriodic->setMaximum(31);

	const auto singleDeadlineLayout = new QHBoxLayout();
	m_ui.widgetSingleDeadline->setLayout(singleDeadlineLayout);
	singleDeadlineLayout->addWidget(new QLabel("Enter the deadline date:"));
	singleDeadlineLayout->addWidget(m_dateEditSingle);
	singleDeadlineLayout->addStretch();

	const auto periodicDeadlineLayout = new QHBoxLayout();
	m_ui.widgetPeriodicDeadline->setLayout(periodicDeadlineLayout);
	periodicDeadlineLayout->addWidget(new QLabel("Enter the deadline month day:"));
	periodicDeadlineLayout->addWidget(m_spinPeriodic);
	periodicDeadlineLayout->addStretch();
}

void month_flow::NewTaskDialog::UpdateGui()
{
	if (IsSingleTaskChosen())
	{
		m_ui.widgetPeriodicDeadline->hide();
		m_ui.widgetSingleDeadline->show();
	}
	else
	{
		m_ui.widgetPeriodicDeadline->show();
		m_ui.widgetSingleDeadline->hide();
	}
}

bool month_flow::NewTaskDialog::IsSingleTaskChosen() const
{
	return m_ui.radioSingleTask->isChecked();
}
