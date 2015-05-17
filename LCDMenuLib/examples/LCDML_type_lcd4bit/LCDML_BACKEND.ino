/* ===================================================================== */
/*
/* LCDMenuLib BACKEND FUNCTION - do not change here something            */
/*
/* ===================================================================== */

/* ********************************************************************* */
void LCDML_BACK_setup(LCDML_BACKEND_control)      
/* ********************************************************************* */
{
  // setup of this backend function is called only at first start or reset 
  #if(_LCDML_DISP_cfg_control == 3)
  pinMode(_LCDML_CONTROL_encoder_pin_a      , INPUT_PULLUP);
  pinMode(_LCDML_CONTROL_encoder_pin_b      , INPUT_PULLUP);
  pinMode(_LCDML_CONTROL_encoder_pin_button , INPUT_PULLUP);
  #endif  
}
boolean LCDML_BACK_loop(LCDML_BACKEND_control)
{ 
  // loop of this backend function
  if(bitRead(LCDML.control, _LCDML_control_funcend)) {    
    LCDML_BACK_reset(LCDML_BACKEND_menu); // reset setup function for DISP function 
    LCDML_BACK_dynamic_setDefaultTime(LCDML_BACKEND_menu); // reset trigger settings
    LCDML_BACK_stopStable(LCDML_BACKEND_menu); // stop an menu function stable    
  }  
   // example for init screen
  #if (_LCDML_DISP_cfg_initscreen == 1)
  if((millis() - g_lcdml_initscreen) >= _LCDML_DISP_cfg_initscreen_time) {
    g_lcdml_initscreen = millis(); // reset init screen time
    LCDML_DISP_jumpToFunc(LCDML_FUNC_initscreen); // jump to initscreen     
  }  
  #endif  
  
  // check control settings of lcdml
  #if(_LCDML_DISP_cfg_control == 0)  
  LCDML_CONTROL_serial();           
  #elif(_LCDML_DISP_cfg_control == 1)  
  LCDML_CONTROL_analog();     
  #elif(_LCDML_DISP_cfg_control == 2)  
  LCDML_CONTROL_digital();     
  #elif(_LCDML_DISP_cfg_control == 3)  
  LCDML_CONTROL_encoder();   
  #endif  
 
  return true;  
}
void LCDML_BACK_stable(LCDML_BACKEND_control)
{
}

/* ===================================================================== */
/*
/* OWM BACKEND FUNCTION */
/*
/* ===================================================================== */
