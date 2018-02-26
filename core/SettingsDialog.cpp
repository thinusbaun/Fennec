#include "SettingsDialog.h"
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QMessageBox>
#include "JSONSyntaxHighlighter.h"

SettingsDialog::SettingsDialog(QWidget* parent, Qt::WindowFlags flags,
                               SettingsProvider& settingsProvider)
    : QDialog(parent, flags), mSettingsProvider(settingsProvider) {
  auto mainLayout = new QGridLayout;
  setLayout(mainLayout);
  auto topLayout = new QHBoxLayout;
  mainLayout->addLayout(topLayout, 0, 0);

  mSettingsEditor = new QPlainTextEdit();
  //  mSettingsEditor->setFontFamily("Courier New");
  auto font = mSettingsEditor->font();
  font.setFamily("Courier");
  mSettingsEditor->setFont(font);
  mSyntaxHighlighter = new JSONSyntaxHighlighter(mSettingsEditor->document());
  mSettingsEditor->setPlainText(mSettingsProvider.getJsonSettings().toJson());
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

void SettingsDialog::acceptClicked() {
  QString errorString;
  if (!mSettingsProvider.trySaveSettings(mSettingsEditor->toPlainText(),
                                         errorString)) {
    auto messageBox = new QMessageBox();
    messageBox->addButton(QMessageBox::Ok);
    messageBox->setText(errorString);
    messageBox->show();
  } else {
    hide();
  }
}

void SettingsDialog::cancelClicked() { hide(); }
