#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "JSONSyntaxHighlighter.h"

#include <QDialog>
#include <QPlainTextEdit>
#include <QPushButton>

class SettingsDialog : public QDialog {
 public:
  SettingsDialog(QWidget* parent, Qt::WindowFlags flags);
  ~SettingsDialog();

 private:
  QPlainTextEdit* mSettingsEditor;
  QPushButton* mAcceptButton;
  QPushButton* mCancelButton;

  JSONSyntaxHighlighter* mSyntaxHighlighter;

 private slots:
  void acceptClicked();
  void cancelClicked();
};

#endif  // SETTINGSDIALOG_H
