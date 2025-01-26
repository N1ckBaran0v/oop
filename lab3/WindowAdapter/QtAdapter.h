#ifndef __QT_ADAPTER_H__
#define __QT_ADAPTER_H__

#include <QPainter>

#include "WindowAdapter.h"

class QtAdapter : public WindowAdapter {
public:
    QtAdapter() = delete;
    QtAdapter(QPainter &, int, int);

    void drawLine(double x0, double y0, double x1, double y1) override;

private:
    QPainter &painter;
    int x = 0, y = 0;
};

#endif // __QT_ADAPTER_H__
