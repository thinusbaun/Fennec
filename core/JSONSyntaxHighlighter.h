#ifndef JSONSYNTAXHIGHLIGHTER_H
#define JSONSYNTAXHIGHLIGHTER_H

#include <QRegExp>
#include <QSyntaxHighlighter>

class JSONSyntaxHighlighter : public QSyntaxHighlighter {
 public:
  JSONSyntaxHighlighter(QTextDocument* document);

 protected:
  virtual void highlightBlock(const QString& text) override;

 private:
  QTextCharFormat mSymbolFormat, mNameFormat, mValueFormat;
  QRegExp mSymbolRegex;
  QRegExp mNameRegex;
  QRegExp mValueRegex;
};

#endif  // JSONSYNTAXHIGHLIGHTER_H
