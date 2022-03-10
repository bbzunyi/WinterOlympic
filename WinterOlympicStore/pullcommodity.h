#ifndef PULLCOMMODITY_H
#define PULLCOMMODITY_H
#include "datastructure.h"
#include <QWidget>

namespace Ui {
class PullCommodity;
}

class PullCommodity : public QWidget
{
    Q_OBJECT

public:
    explicit PullCommodity(QWidget *parent = nullptr);
    ~PullCommodity();

private:
    Ui::PullCommodity *ui;
};

#endif // PULLCOMMODITY_H
