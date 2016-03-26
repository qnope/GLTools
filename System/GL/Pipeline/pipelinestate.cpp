#include "pipelinestate.hpp"

void PipelineState::perform() const {
    glColorMask(colorState.rMask, colorState.gMask,
                colorState.bMask, colorState.aMask);

    if(blendingState.blendingEnable == true) {
        glEnable(GL_BLEND);
    }

    else
        glDisable(GL_BLEND);
}
