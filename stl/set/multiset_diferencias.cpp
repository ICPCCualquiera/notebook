struct MultisetDiferencias {
   Multiset elementos, diferencias;
   void insertar (int x) {
      if (elementos.count(x)) {
         elementos.insertar(x);
         diferencias.insertar(0);
         return;
      }
      elementos.insertar(x);
      int m = elementos.min(), M = elementos.max();
      int a, b;
      if (x < M) {
         b = elementos.primer_mayor(x);
         diferencias.insertar(b - x);
      }
      if (m < x) {
         a = elementos.primer_menor(x);
         diferencias.insertar(x - a);
      }
      if (m < x && x < M) diferencias.eliminar(b - a);
   }
   void eliminar (int x) {
      assert(elementos.count(x));
      if (elementos.count(x) > 1) {
         elementos.eliminar(x);
         diferencias.eliminar(0);
         return;
      }
      int m = elementos.min(), M = elementos.max();
      elementos.eliminar(x);
      int a, b;
      if (x < M) {
         b = elementos.primer_mayor(x);
         diferencias.eliminar(b - x);
      }
      if (m < x) {
         a = elementos.primer_menor(x);
         diferencias.eliminar(x - a);
      }  
      if (m < x && x < M) diferencias.insertar(b - a);
   }
};