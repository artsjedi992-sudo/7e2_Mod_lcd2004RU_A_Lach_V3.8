//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ***** Print ***** /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void Print()
{   
     if      (err_0_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print("      WARNING       ");
      lcd.setCursor(0, 1);
      lcd.print("Set joystick to     ");
      lcd.setCursor(0, 2);
      lcd.print("   neutral position "); 
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      return;   
   } 
  
   if      (err_1_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print(" WARNING:           ");
      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("   SET THE STOPS!   "); 
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      return;   
   }
   else if (err_2_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print(" WARNING:           ");
      lcd.setCursor(0, 1);     
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("SET CARRIAGE TO HOME");
      lcd.setCursor(0, 3);
      lcd.print("    POSITION!       ");      
      return;   
   }
   else if (Complete_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print("                    ");
      lcd.setCursor(0, 1);     
      lcd.print("OPERATION COMPLETE! ");
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(0, 3);
      lcd.print("                    ");       
      return;   
   }  
   else if (isPausedAfterStep == true)
   {
      lcd.setCursor(0, 0);
      lcd.print("        PAUSE       ");
      lcd.setCursor(0, 1);     
      lcd.print("  Press UP to resume");
      lcd.setCursor(0, 2);
      lcd.print("  Press the upper   ");
      lcd.setCursor(0, 3);
      lcd.print("   MENU button \3    ");       
      return;   
   }   
     
     if ((Mode == Mode_Feed    && SelectMenu == 3) || 
         (Mode == Mode_Cone_L  && SelectMenu == 3) ||
         (Mode == Mode_Cone_R  && SelectMenu == 3) || 
         (Mode == Mode_aFeed   && SelectMenu == 3) || 
         (Mode == Mode_Sphere  && SelectMenu == 3) ||
         (Mode == Mode_Thread  && SelectMenu == 3))
   {
         lcd.setCursor(0, 0);
         lcd.print(" Enter part diameter");
         lcd.setCursor(0, 1);
         lcd.print("                    ");
         lcd.setCursor(0, 2);
         lcd.print("\3\4                  ");
         lcd.setCursor(0, 3);
         if (MSize_X_mm <= 0)
         lcd.print(" Diameter    ");
         else 
         lcd.print(" Diameter   -"); 
         snprintf(LCD_Row_7, 7, "%3ld.%02d", abs(MSize_X_mm/100), abs(MSize_X_mm%100));
         lcd.print(LCD_Row_7);
         lcd.print("mm");  
     }
     ////////////////////////дистанционные лимиты/////////////////////////////////
     if ((Mode == Mode_Feed      && SelectMenu == 4) || 
         (Mode == Mode_Cone_L    && SelectMenu == 4) ||
         (Mode == Mode_Cone_R    && SelectMenu == 4) || 
         (Mode == Mode_aFeed     && SelectMenu == 4) || 
         (Mode == Mode_Thread    && SelectMenu == 4))
        {
         lcd.setCursor(0, 0);
          lcd.print(" REMOTE LIMITS      ");
          lcd.setCursor(0, 1);
          lcd.print("                    ");
          lcd.setCursor(0, 2); 
          lcd.print("Distance            "); 
          lcd.setCursor(0, 3);
          lcd.print("to limit: ");
          snprintf(LCD_Row_8, sizeof(LCD_Row_8), "%3ld.%03d", (Distance_mm/2)/1000, (Distance_mm/2)%1000);  
          lcd.print(LCD_Row_8);
          lcd.setCursor(18, 3);
          lcd.print("mm");
        }

     ///////////////////////////////////////////////////////////////
     if ((Mode == Mode_Feed      && SelectMenu == 1) || 
         (Mode == Mode_Cone_L    && SelectMenu == 1) ||
         (Mode == Mode_Cone_R    && SelectMenu == 1 && Sub_Mode_Cone != Sub_Mode_Cone_Int) || 
         (Mode == Mode_aFeed     && SelectMenu == 1) || 
         (Mode == Mode_Sphere    && SelectMenu == 1) ||
         (Mode == Mode_Thread    && SelectMenu == 1))
       {
                   ///////         Линейка     ////////
         
         lcd.setCursor(0, 1);
         if (MSize_X_mm <= 0)
         snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MSize_X_mm/100), abs(MSize_X_mm%100));
         else 
         snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MSize_X_mm/100), abs(MSize_X_mm%100));
         lcd.print(LCD_Row_7);
         lcd.print(" ");

         lcd.setCursor(0, 2);
         if (Size_X_mm <= 0)
         snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
         //snprintf(LCD_Row_6, 20, "X %5ld", abs(X_pos)); //***только для отладки
         else 
         snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
         //snprintf(LCD_Row_6, 20, "X-%5ld", abs(X_pos)); //***только для отладки
         lcd.print(LCD_Row_6);
         lcd.print(" ");
                  
         lcd.setCursor(0, 3);
         if (Size_Z_mm <= 0)
         snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
         //snprintf(LCD_Row_5, 20, "Z %5ld", abs(Z_pos*2)); //***только для отладки
         else 
         snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
         //snprintf(LCD_Row_5, 20, "Z-%5ld", abs(Z_pos*2)); //***только для отладки
         lcd.print(LCD_Row_5);
         lcd.print(" "); 
   }
//================================    РЕЗЬБА   ===========================================================================================================================================

   if (Mode == Mode_Thread)
   { 
    if (SelectMenu == 1)
     {      
         if ((Ph > 1) && (ConL_Thr_flag == false || ConR_Thr_flag == false))
            {
            lcd.setCursor(8, 0);
            lcd.print("\2  Thread");
            snprintf(LCD_Row_1, 18, " %2d", Gewinde_flag);
            lcd.print(LCD_Row_1);
             }
      else if (ConL_Thr_flag == true && Ph == 1)
             {
            lcd.setCursor(8, 0);
            snprintf(LCD_Row_1, 8, "<%s ", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.print("Thread");
             }
      else if (ConR_Thr_flag == true && Ph == 1)
            {
           lcd.setCursor(8, 0);
            snprintf(LCD_Row_1, 8, ">%s ", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.print("Thread");  
            }
            else 
             {
            lcd.setCursor(8, 0);
            lcd.print("\2  Thread   ");
             }
           
            lcd.setCursor(8, 2);
            lcd.print(" Cycles:   ");                                             
            lcd.setCursor(8, 1);
            lcd.print(" Pitch: ");        
            snprintf(LCD_Row_2, 7, "%s", Thread_Info[Thread_Step].Thread_Print);  
            lcd.print(LCD_Row_2);
     
      if (Sub_Mode_Thread == Sub_Mode_Thread_Int)
            {lcd.setCursor(0, 0);
             if (Kzr == 1)  {lcd.print("1Int.   ");}
             else if (Kzr == 2)  {lcd.print("2Int.    ");}
             else if (Kzr == 3)  {lcd.print("3Int.    ");} 
             else if (Kzr == 4)  {lcd.print("4Int.    ");}
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass - Pass_Nr+1 + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4);}
      else if (Sub_Mode_Thread == Sub_Mode_Thread_Man)
             {lcd.setCursor(0, 0);
             if (Kzr == 1)  {lcd.print("1Manual ");}
             else if (Kzr == 2)  {lcd.print("2Manual ");}
             else if (Kzr == 3)  {lcd.print("3Manual ");}
             else if (Kzr == 4)  {lcd.print("4Manual ");}
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4);} 
      else if (Sub_Mode_Thread ==  Sub_Mode_Thread_Ext)
             {lcd.setCursor(0, 0);
             if (Kzr == 1)  {lcd.print("1External");}
             else if (Kzr == 2)  {lcd.print("2External");}
             else if (Kzr == 3)  {lcd.print("3External");}
             else if (Kzr == 4)  {lcd.print("4External");}
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass - Pass_Nr+1 + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4);}
                      
            if (Ph >1)
            {
             int Thstep_mm = Thread_Info[Thread_Step].Step * 100 * Ph;  
             lcd.setCursor(8, 3); 
             lcd.print(" Travel:"); 
             snprintf(LCD_Row_3, 5, "%1d.%02d", Thstep_mm/100, Thstep_mm%100);
             lcd.print(LCD_Row_3);
             lcd.print("mm");  
            }
            else 
            { 
             lcd.setCursor(8, 3);
             lcd.print(" RPM: "); 
             snprintf(LCD_Row_3, 4, "%3d", Thread_Info[Thread_Step].Limit_Print); 
             lcd.print(LCD_Row_3);
            }
         } 
         else if (SelectMenu == 2) 
         {
             int Thstep_mm = Thread_Info[Thread_Step].Step * 100 * Ph;  
             lcd.setCursor(0, 0);                            
             lcd.print("Finish passes: \1\2 "); 
             snprintf(LCD_Row_3, 3, "%2d", PASS_FINISH + Pass_Fin);
             lcd.print(LCD_Row_3);
             lcd.setCursor(0, 1);
             lcd.print("Thread starts: \3\4 ");
             snprintf(LCD_Row_4, 3, "%2d", Ph);
             lcd.print(LCD_Row_4);
             lcd.setCursor(0, 2); 
             lcd.print("Thread travel:   "); 
             snprintf(LCD_Row_5, 5, "%1d.%02d", Thstep_mm/100, Thstep_mm%100);
             lcd.print(LCD_Row_5);
             lcd.print("mm"); 
             lcd.setCursor(0, 3);
             lcd.print("Thread pitch:   ");        
             snprintf(LCD_Row_6, 7, "%s", Thread_Info[Thread_Step].Thread_Print);  
             lcd.print(LCD_Row_6);
    
          }
       }
   
//================================    ПОДАЧА СИНХРОННАЯ   ===========================================================================================================================================
  
   else if (Mode == Mode_Feed)
   {  
          if (SelectMenu == 1)
           {  
       if  (OTSKOK_Z < REBOUND_Z || TENSION_Z > 1)  
           {
            lcd.setCursor(8, 0);
            lcd.print("\2  Sync feed *");}
            else{
            lcd.setCursor(8, 0);
            lcd.print("\2  Sync feed  ");          
            }
            lcd.setCursor(8, 1);      
            lcd.print(" Feed:");
            snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
            lcd.print(LCD_Row_2);
            lcd.setCursor(8, 2);
            lcd.print(" Cycles:   ");
            lcd.setCursor(8, 3); 
            lcd.print(" Depth \6:");
            snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
            lcd.print(LCD_Row_4); 
                  
      switch(Sub_Mode_Feed)
      {
        case Sub_Mode_Feed_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Internal");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);     
             break;
        case Sub_Mode_Feed_Man:             
             lcd.setCursor(0, 0);      
             lcd.print(" Manual  ");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);            
             break;
        case Sub_Mode_Feed_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" External");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);           
             break;
            }                    
         }
              else if (SelectMenu == 2){
              lcd.setCursor(0, 0);
              lcd.print("Rebound Z: \1\2");
              snprintf(LCD_Row_5, 16, " %2ld.%02dmm", abs(OTSKOK_Z_mm/100), abs(OTSKOK_Z_mm%100));
              lcd.print(LCD_Row_5);  
              lcd.setCursor(0, 1);
              lcd.print("                    ");
              lcd.setCursor(0, 2);
              lcd.print("Release tension \3 ");
              lcd.setCursor(0, 3);
              lcd.print("Tension Z:  \4"); 
              snprintf(LCD_Row_6, 16, " %2ld.%02dmm", abs(TENSION_Z_mm/100), abs(TENSION_Z_mm%100));
              lcd.print(LCD_Row_6);
     }
   }
   
//================================    ПОДАЧА АСИНХРОННАЯ    ===========================================================================================================================================

   else if (Mode == Mode_aFeed)
   {   
          if (SelectMenu == 1) 
           {
            lcd.setCursor(8, 0);
            lcd.print("\2  Async feed");
            lcd.setCursor(8, 1);      
            lcd.print(" Feed: ");
            snprintf(LCD_Row_1, 4, "%3d", aFeed_mm);
            lcd.print(LCD_Row_1);
            lcd.setCursor(8, 2);
            lcd.print(" Cycles:   ");
            lcd.setCursor(8, 3); 
            lcd.print("Depth R:");
            snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
            lcd.print(LCD_Row_4);

      switch(Sub_Mode_aFeed)
      {
        case Sub_Mode_aFeed_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Internal");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);            
             break;
        case Sub_Mode_aFeed_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Manual  ");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);           
             break;
        case Sub_Mode_aFeed_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" External");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);               
             break;
            }                               
    }
        else if (SelectMenu == 2)
            {
             lcd.setCursor(0, 0);
             lcd.print("Current angle:");
             snprintf(LCD_Row_2, 7, "%3ld.%01ld", Spindle_Angle/1000, Spindle_Angle%1000/100);
             lcd.print(LCD_Row_2);
             lcd.print("\5");                           
             lcd.setCursor(0, 1);
             lcd.print("Divide circle by:");
             snprintf(LCD_Row_1, 5,"%3d " , Total_Tooth);
             lcd.print(LCD_Row_1);
             lcd.print("\3\4");                           
             lcd.setCursor(0, 2);
             lcd.print("Select mark:");
             snprintf(LCD_Row_3, 5, "%3d ", Current_Tooth);
             lcd.print(LCD_Row_3);
             lcd.print("\1\2");
             lcd.setCursor(0, 3);
             lcd.print("Sector angle:");
             snprintf(LCD_Row_4, 7, "%3ld.%01ld", Required_Angle/1000, Required_Angle%1000/100);
             lcd.print(LCD_Row_4);
             lcd.print("\5");
            }   
   }
   
//================================    КОНУС ЛЕВЫЙ <    ===========================================================================================================================================

   else if (Mode == Mode_Cone_L)
   {
          if (SelectMenu == 1)
           {
            lcd.setCursor(8, 0);
            snprintf(LCD_Row_1, 8, "<%s ", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.setCursor(13, 0);
            lcd.print(" Cone  ");                                   
            lcd.setCursor(8, 1);      
            lcd.print(" Feed:");
            snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
            lcd.print(LCD_Row_2);
            lcd.setCursor(8, 2);
            lcd.print(" Cycles:   ");
            lcd.setCursor(8, 3); 
            lcd.print(" Depth \6:");
            snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
            lcd.print(LCD_Row_4); 
      
      switch(Sub_Mode_Cone)
      {
        case Sub_Mode_Cone_Int:
             lcd.setCursor(0, 0);      
             lcd.print("Internal");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);         
             break;
        case Sub_Mode_Cone_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Manual  ");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);           
             break;
        case Sub_Mode_Cone_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" External");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);          
             break;
            }                    
           }
           else if (SelectMenu == 2)
           {
            lcd.setCursor(0, 0);
            lcd.print("Cone   < ");
            snprintf(LCD_Row_1, 5, "%s", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.setCursor(13, 0);
            lcd.print("    \1 \2");
            lcd.setCursor(0, 2);
            lcd.print("Conical           \3 ");
            if (ConL_Thr_flag == true){
            lcd.setCursor(0, 1);
            lcd.print("   Thread mode      ");  
            lcd.setCursor(0, 3);
            lcd.print("Thread: ON      \4 ");}
            else
            {             
             if ((Sub_Mode_Cone == Sub_Mode_Cone_Int) || ( Sub_Mode_Cone == Sub_Mode_Cone_Ext))
              {
               Cs_Divisor = (Cone_Info[Cone_Step].Cs_Div);
               Cm_Divisor = (Cone_Info[Cone_Step].Cm_Div);
               long long temp = (long long)Ap * Cs_Divisor + ((long long)Ap * Cm_Divisor + 5000LL) / 10000LL;
               long DlinaC = (long)((temp * Pass_Total + 1LL) / 2LL);  // +1 для округления   
               lcd.setCursor(0, 1);  
               lcd.print("Int. cone length");     
               snprintf(LCD_Row_8, 5, "%3d.", DlinaC/100);
               lcd.print(LCD_Row_8);
               snprintf(LCD_Row_9, 3, "%02d",  DlinaC%100);
               lcd.print(LCD_Row_9);
              }
             else 
              {
               lcd.setCursor(0, 1);
               lcd.print("                    ");
              }    
            lcd.setCursor(0, 3);
            lcd.print("Thread: OFF     \4 ");}
           } 
      }
   
//================================    КОНУС ПРАВЫЙ >   ===========================================================================================================================================

   else if (Mode == Mode_Cone_R)
   {
          if (SelectMenu == 1 && Sub_Mode_Cone != Sub_Mode_Cone_Int)
           {
            lcd.setCursor(8, 0);
            snprintf(LCD_Row_1, 8, ">%s ", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.setCursor(13, 0);
            lcd.print(" Cone  ");                                   
            lcd.setCursor(8, 1);      
            lcd.print(" Feed:");
            snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
            lcd.print(LCD_Row_2);
            lcd.setCursor(8, 2);
            lcd.print(" Cycles:   ");
            lcd.setCursor(8, 3); 
            lcd.print(" Depth \6:");
            snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
            lcd.print(LCD_Row_4);  
            
      switch(Sub_Mode_Cone)
      {
        case Sub_Mode_Cone_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Manual  ");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);            
             break;
        case Sub_Mode_Cone_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" External");
             lcd.setCursor(18, 2);
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);        
             break;
            }               
           }
           else if (SelectMenu == 1 && Sub_Mode_Cone == Sub_Mode_Cone_Int)
           {
            lcd.setCursor(0, 0);
             lcd.print("                    ");
             lcd.setCursor(0, 1);     
             lcd.print("  Mode not available! ");
             lcd.setCursor(0, 2);
             lcd.print("                    ");
             lcd.setCursor(0, 3);
             lcd.print("                    ");    
           }
           else if (SelectMenu == 2)
           {
            lcd.setCursor(0, 0);
            lcd.print("Cone   > ");
            snprintf(LCD_Row_1, 5, "%s", Cone_Info[Cone_Step].Cone_Print);
            lcd.print(LCD_Row_1);
            lcd.setCursor(13, 0);
            lcd.print("    \1 \2");
            lcd.setCursor(0, 2);
            lcd.print("Conical           \3 ");
            if (ConR_Thr_flag == true){
            lcd.setCursor(0, 1);
            lcd.print("   Thread mode      "); 
            lcd.setCursor(0, 3);
            lcd.print("Thread: ON      \4 ");}
            else
            {             
             if ((Sub_Mode_Cone == Sub_Mode_Cone_Int) || ( Sub_Mode_Cone == Sub_Mode_Cone_Ext))
              {
               Cs_Divisor = (Cone_Info[Cone_Step].Cs_Div);
               Cm_Divisor = (Cone_Info[Cone_Step].Cm_Div);
               long long temp = (long long)Ap * Cs_Divisor + ((long long)Ap * Cm_Divisor + 5000LL) / 10000LL;
               long DlinaC = (long)((temp * Pass_Total + 1LL) / 2LL);  // +1 для округления   
               lcd.setCursor(0, 1);  
               lcd.print("Int. cone length");     
               snprintf(LCD_Row_8, 5, "%3d.", DlinaC/100);
               lcd.print(LCD_Row_8);
               snprintf(LCD_Row_9, 3, "%02d",  DlinaC%100);
               lcd.print(LCD_Row_9);
              }
             else 
              {
               lcd.setCursor(0, 1);
               lcd.print("                    ");
              }    
            lcd.setCursor(0, 3);
            lcd.print("Thread: OFF     \4 ");}
            

           }  
         }
   
//================================    РЕЖИМ ШАРА (Шароточка)   ===========================================================================================================================================

   else if (Mode == Mode_Sphere)
   { 
         
     if (SelectMenu == 1 && Sub_Mode_Sphere != Sub_Mode_Sphere_Int)
      {
        if (Raz == 1) // режим шара
        {  
         lcd.setCursor(0, 0);
         lcd.print("BALL \6");
         snprintf(LCD_Row_1, 5, "%2ld.%01ld", Sph_R_mm * 2 / 100, Sph_R_mm * 2 / 10 %10);
         lcd.print(LCD_Row_1);
         lcd.print("mm");
         lcd.setCursor(8, 1);      
         lcd.print(" Feed:");
         snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
         lcd.print(LCD_Row_2);
         
          if (Sub_Mode_Sphere == Sub_Mode_Sphere_Man)
          {  
             lcd.setCursor(11, 0);
             lcd.print(" Disabled");
          }
          else if (Sub_Mode_Sphere == Sub_Mode_Sphere_Ext)
          {  
             lcd.setCursor(11, 0);
             lcd.print(" Enabled");
          }
          lcd.setCursor(8, 2);
          lcd.print(" Nose: \6"); 
          snprintf(LCD_Row_3, 5, "%ld.%02ld", Bar_R_mm*2/100, Bar_R_mm*2%100);
          lcd.print(LCD_Row_3);
          lcd.setCursor(8, 3);
          lcd.print(" Passes:");
          snprintf(LCD_Row_4, 4, "%3ld", Pass_Total_Sphr+2-Pass_Nr); 
          lcd.print(LCD_Row_4); 
        }  
        //////////////////////////////// РЕЖИМ ОТРЕЗАНИЯ С РАЗБЕЖКОЙ //////////////////////////////////////
        else if (Raz == 2)
         {  
         lcd.setCursor(0, 0);
         lcd.print("CUT-OFF");
         lcd.setCursor(9, 0);
         snprintf(LCD_Row_1, 5, "%3ld", Raz_R);
         lcd.print(LCD_Row_1);
         lcd.setCursor(8, 1);      
         lcd.print(" Feed:");
         snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
         lcd.print(LCD_Row_2);
         
          if (Sub_Mode_Sphere == Sub_Mode_Sphere_Man)
          {  
             lcd.setCursor(12, 0);
             lcd.print(" mm\6 Man");
          }
          else if (Sub_Mode_Sphere == Sub_Mode_Sphere_Ext)
          {  
             lcd.setCursor(12, 0);
             lcd.print( " mm\6 Auto");
          }
          lcd.setCursor(8, 2);
          lcd.print(" Step  \6:"); 
          snprintf(LCD_Row_3, 5, "%1d.%02d", Ap/100, Ap%100);
          lcd.print(LCD_Row_3);
          lcd.setCursor(8, 3);
          lcd.print(" Offset:");
          snprintf(LCD_Row_4, 5, "%1d.%02d", Staggered_Width/100, Staggered_Width%100); 
          lcd.print(LCD_Row_4); 
        }   
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////
      }
      else if (SelectMenu == 2)
      {  
         lcd.setCursor(0, 0);
         lcd.print("Cutter width: ");
         snprintf(LCD_Row_1, 5, "%1d.%02d", Cutter_Width/100, Cutter_Width%100);
         lcd.print(LCD_Row_1);
         lcd.print("mm");
         lcd.setCursor(0, 1);
         lcd.print("Step along Z: ");
         snprintf(LCD_Row_2, 5, "%1d.%02d", Cutting_Width/100, Cutting_Width%100);
         lcd.print(LCD_Row_2);
         lcd.print("mm"); 
         lcd.setCursor(0, 2);
         lcd.print("                    ");
         lcd.setCursor(0, 3);
         lcd.print("                    ");
      } 
       if (Sub_Mode_Sphere == Sub_Mode_Sphere_Int)
         {
             lcd.setCursor(0, 0);
             lcd.print("                    ");
             lcd.setCursor(0, 1);     
             lcd.print("  Mode not available! ");
             lcd.setCursor(0, 2);
             lcd.print("                    ");
             lcd.setCursor(0, 3);
             lcd.print("                    "); 
         }            
   }
//================================    Делилка  ===========================================================================================================================================
   else if (Mode == Mode_Divider)
{
                       

                           lcd.setCursor(0, 0);
                           lcd.print("   Current angle     ");
                           lcd.setCursor(0, 1);
                           lcd.print("       ");
                           snprintf(LCD_Row_2, 9, "%3ld.%01ld", Spindle_Angle/1000, Spindle_Angle%1000/100);
                           lcd.print(LCD_Row_2);
                           lcd.print("\5       "); 
                           lcd.setCursor(0, 2);   
                           lcd.print("                    "); 
                           lcd.setCursor(0, 3);
                           lcd.print("Reset: press SELECT ");                        
                  
                         
                          } 


//================================    Зарезервированный режим  ===========================================================================================================================================
   
   else if (Mode == Mode_Reserve)  
   {
           
          lcd.setCursor(0, 0);
          lcd.print("                    ");
          lcd.setCursor(0, 1);
          lcd.print("      RESERVED      "); 
          lcd.setCursor(0, 2);
          lcd.print("                    ");
          lcd.setCursor(0, 3);
          lcd.setCursor(0, 3);
          lcd.print(" Hand_Count ");
          snprintf(LCD_Row_1, sizeof(LCD_Row_1), "%8ld", Hand_Count);
          lcd.print(LCD_Row_1);
         
   }
      
 
}
