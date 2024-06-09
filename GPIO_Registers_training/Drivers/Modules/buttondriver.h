/*
 * buttondriver.h
 *
 *  Created on: Feb 26, 2023
 *      Author: kinan
 */

#ifndef MODULES_BUTTONDRIVER_H_
#define MODULES_BUTTONDRIVER_H_

// void button_init();
void button_init_interrupt();
int get_button_state(void);

#endif /* MODULES_BUTTONDRIVER_H_ */
