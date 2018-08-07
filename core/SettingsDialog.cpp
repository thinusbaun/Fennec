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

int SettingsDialog::exec() {
  auto config = mSettingsProvider.saveSettings();
  mSettingsEditor->setPlainText(config);
  return QDialog::exec();
}
void SettingsDialog::acceptClicked() {
  QString errorString;
  auto result =
      mSettingsProvider.loadSettings(mSettingsEditor->toPlainText().toUtf8());
  if (!result.first) {
    auto messageBox = new QMessageBox();
    messageBox->addButton(QMessageBox::Ok);
    messageBox->setText(
        QString("Load settings failed!\n%1").arg(result.second));
    messageBox->show();
  } else {
    accept();
  }
}

void SettingsDialog::cancelClicked() { reject(); }
