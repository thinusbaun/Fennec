#include "SettingsDialog.h"
#include <QHBoxLayout>
#include "JSONSyntaxHighlighter.h"

SettingsDialog::SettingsDialog(QWidget* parent, Qt::WindowFlags flags)
    : QDialog(parent, flags) {
  auto mainLayout = new QGridLayout;
  setLayout(mainLayout);
  auto topLayout = new QHBoxLayout;
  mainLayout->addLayout(topLayout, 0, 0);

  mSettingsEditor = new QPlainTextEdit();
  //  mSettingsEditor->setFontFamily("Courier New");
  auto font = mSettingsEditor->font();
  font.setFamily("monospace");
  mSettingsEditor->setFont(font);
  mSyntaxHighlighter = new JSONSyntaxHighlighter(mSettingsEditor->document());
  topLayout->addWidget(mSettingsEditor);

  auto buttonLayout = new QHBoxLayout;
  mAcceptButton = new QPushButton("Ok");
  connect(mAcceptButton, &QPushButton::clicked, this,
          &SettingsDialog::acceptClicked);
  buttonLayout->addWidget(mAcceptButton);

  mCancelButton = new QPushButton("Cancel");
  connect(mCancelButton, &QPushButton::clicked, this,
          &SettingsDialog::cancelClicked);
  buttonLayout->addWidget(mCancelButton);

  mainLayout->addLayout(buttonLayout, 1, 0);
}

SettingsDialog::~SettingsDialog() { delete mSyntaxHighlighter; }

void SettingsDialog::acceptClicked() { hide(); }

void SettingsDialog::cancelClicked() { hide(); }
