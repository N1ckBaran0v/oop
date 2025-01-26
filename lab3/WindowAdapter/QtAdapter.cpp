#include <cmath>

#include "QtAdapter.h"

QtAdapter::QtAdapter(QPainter &painter, int x, int y)
    : painter(painter), x(x), y(y) {}

void QtAdapter::drawLine(double x0, double y0, double x1, double y1) {
    painter.drawLine(
        x + static_cast<int>(round(x0)), y - static_cast<int>(round(y0)),
        x + static_cast<int>(round(x1)), y - static_cast<int>(round(y1)));
}
