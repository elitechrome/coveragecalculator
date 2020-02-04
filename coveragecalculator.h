#ifndef COVERAGECALCULATOR_H
#define COVERAGECALCULATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CoverageCalculator; }
QT_END_NAMESPACE

class CoverageCalculator : public QWidget
{
    Q_OBJECT

public:
    CoverageCalculator(QWidget *parent = nullptr);
    ~CoverageCalculator();

private slots:
    void on_OpenButton_clicked();

private:
    Ui::CoverageCalculator *ui;
};
#endif // COVERAGECALCULATOR_H
