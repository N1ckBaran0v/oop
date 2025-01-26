#ifndef __WINDOW_ADAPTER_H__
#define __WINDOW_ADAPTER_H__

class WindowAdapter {
public:
    virtual ~WindowAdapter() = default;

    virtual void drawLine(double x0, double y0, double x1, double y1) = 0;
};

#endif // __WINDOW_ADAPTER_H__

