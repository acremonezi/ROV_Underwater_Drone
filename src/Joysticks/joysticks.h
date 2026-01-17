#ifndef JOYSTICKS_H

    #define JOYSTICKS_H

        extern int Joystick_1X_Value;
        extern int Joystick_1X_RawValue;

        extern int Joystick_1Y_Value;
        extern int Joystick_1Y_RawValue;

        extern int Joystick_2Y_Value;
        extern int Joystick_2Y_RawValue;

        void Joystick_Setup();
        void Joysticks_Update();
        void Joysticks_Print();

#endif