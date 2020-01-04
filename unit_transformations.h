#pragma once

namespace ut
{
    inline float mixf(float f1, float f2, float t) { return f1 * (1 - t) + f2 * t; }
    
    inline float smooth_start2f(float t) { return t * t; }
    inline float smooth_start3f(float t) { return t * t * t; }
    inline float smooth_start4f(float t) { return t * t * t * t; }
    inline float smooth_start5f(float t) { return t * t * t * t * t; }

    inline float smooth_stop2f(float t) { return 1 - (1 - t) * (1 - t); }
    inline float smooth_stop3f(float t) { return 1 - (1 - t) * (1 - t) * (1 - t); }
    inline float smooth_stop4f(float t) { return 1 - (1 - t) * (1 - t) * (1 - t) * (1 - t); }
    inline float smooth_stop5f(float t) { return 1 - (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 - t); }

    inline float smooth_step2f(float t) { return mixf(smooth_start2f(t), smooth_stop2f(t), t); }
    inline float smooth_step3f(float t) { return mixf(smooth_start3f(t), smooth_stop3f(t), t); }
    inline float smooth_step4f(float t) { return mixf(smooth_start4f(t), smooth_stop4f(t), t); }
    inline float smooth_step5f(float t) { return mixf(smooth_start5f(t), smooth_stop5f(t), t); }
}