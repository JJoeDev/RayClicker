#ifndef RAYCLICKER_EASEING_H
#define RAYCLICKER_EASEING_H

static inline float easeLinear(float curTime, float startVal, float change, float duration){return change * curTime / duration + startVal;}
static inline float easeOutBack(float t, const float start, float target, float dur, const float overShoot){
    t = t / dur - 1.0;
    return target * (t * t * ((overShoot + 1.0f) * t + overShoot) + (1.0f - start / target)) + start;
}

#endif //RAYCLICKER_EASEING_H
