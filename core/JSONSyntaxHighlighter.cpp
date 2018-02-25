#include "JSONSyntaxHighlighter.h"

#include <QFont>

JSONSyntaxHighlighter::JSONSyntaxHighlighter(QTextDocument* document)
    : QSyntaxHighlighter(document) {
  mSymbolFormat.setForeground(Qt::red);
  mSymbolFormat.setFontWeight(QFont::Bold);

  mNameFormat.setForeground(Qt::blue);
  mNameFormat.setFontWeight(QFont::Bold);
  mNameFormat.setFontItalic(true);

  mValueFormat.setForeground(Qt::darkGreen);

  mSymbolRegex.setPattern(R"((\{|\}|\[|\]|\:|\,))");

  mNameRegex.setPattern(R"(\".*\" *\:)");
  mNameRegex.setMinimal(true);

  mValueRegex.setPattern(R"(\: *\".*\")");
  mValueRegex.setMinimal(true);
}

void JSONSyntaxHighlighter::highlightBlock(const QString& text) {
  auto index = mSymbolRegex.indexIn(text);

  while (index >= 0) {
    auto length = mSymbolRegex.matchedLength();
    setFormat(index, length, mSymbolFormat);
    index = mSymbolRegex.indexIn(text, index + length);
  }

  QString replacedText = text;
  replacedText.replace(R"(\\")", "  ");

  index = mNameRegex.indexIn(text);
  while (index >= 0) {
    auto length = mNameRegex.matchedLength();
    setFormat(index, length, mNameFormat);
    index = mNameRegex.indexIn(text, index + length);
  }

  index = mValueRegex.indexIn(text);
  while (index >= 0) {
    auto length = mValueRegex.matchedLength();
    setFormat(index, length, mValueFormat);
    index = mValueRegex.indexIn(text, index + length);
  }
}
