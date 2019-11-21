/**
 *!
 * \file        b_battery.c
 * \version     v0.0.1
 * \date        2019/06/05
 * \author      Bean(notrynohigh@outlook.com)
 *******************************************************************************
 * @attention
 * 
 * Copyright (c) 2019 Bean
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************
 */
  
/*Includes ----------------------------------------------*/ 
#if _BATTERY_ENABLE
#include "b_battery.h" 
/** 
 * \addtogroup BABYOS
 * \{
 */

/** 
 * \addtogroup BATTERY
 * \brief 
 * \{
 */


/** 
 * \defgroup BATTERY_Private_TypesDefinitions
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BATTERY_Private_Defines
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BATTERY_Private_Macros
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BATTERY_Private_Variables
 * \{
 */
static uint16_t bLowThreshold = _BATTERY_THRESHOLD;  
static uint8_t bBatteryStatus = bBAT_STA_NORMAL;
/**
 * \}
 */
   
/** 
 * \defgroup BATTERY_Private_FunctionPrototypes
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BATTERY_Private_Functions
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \addtogroup BATTERY_Exported_Functions
 * \{
 */
/**
 * \brief Get Voltage (mV)
 * \param pmV Pointer to value
 * \retval Result
 *          \arg 0  OK
 *          \arg -1 ERR
 */ 
#if __GNUC__ 
int __attribute__((weak)) bBatteryGetmV(uint16_t *pmV)
#else
__weak int bBatteryGetmV(uint16_t *pmV)
#endif
{
    if(pmV == NULL)
    {
        return -1;    
	}
    *pmV = bLowThreshold;
    return 0;
}

/**
 * \brief Read V and compare with bLowThreshold \ref _BATTERY_THRESHOLD
 * \retval Result
 *          \arg 0  OK
 *          \arg -1 ERR
 */
int bBatteryCore()
{
    uint16_t mV = 0;
    if(bBatteryGetmV(&mV) == 0)
    {
        if(mV >= bLowThreshold)
        {
            bBatteryStatus = BATTERY_STA_NORMAL;
        }
        else
        {
            bBatteryStatus = BATTERY_STA_LOW;
        }
        return 0;
    }
    return -1;
}


/**
 * \brief Get Status 
 * \retval Battery Status
 *          \arg \ref bBAT_STA_NORMAL
 *          \arg \ref bBAT_STA_LOW 
 */
uint8_t bBatGetStatus()
{
    return bBatteryStatus;
}

/**
 * \}
 */


/**
 * \}
 */


/**
 * \}
 */
#endif

/************************ Copyright (c) 2019 Bean *****END OF FILE****/

