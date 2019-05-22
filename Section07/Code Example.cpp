bool TAS(bool lock) {
   if (lock) {
         return true;
   }
   else {
        lock = true;
        return false;
   }
}

bool CAS(int* p, int old, int new) {
   if (*p != old) {
               return false;
       }
   *p = new;
         return true;
}

volatile bool lock = false;
 void critical() {
      while (TAS(&lock) == false);
      // Critical section
      lock = 0;
 }
