#ifndef     MOTORS_H

    #define     MOTORS_H

        void Motors_Setup();

        void Motor_Right_Go();
        void Motor_Left_Go();
        void Motor_Top_Go();
        
        void Motor_Right_Stop();
        void Motor_Left_Stop();
        void Motor_Top_Stop();

        void Motor_Right_Break();
        void Motor_Left_Break();
        void Motor_Top_Break();

        void Motor_Right_Get_PWM();
        void Motor_Left_Get_PWM();
        void Motor_Top_Get_PWM();

        void Motor_Right_Test();
        void Motor_Left_Test();
        void Motor_Top_Test();

#endif
