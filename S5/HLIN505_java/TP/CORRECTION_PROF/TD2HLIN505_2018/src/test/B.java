package test;

public class B extends A{
	
void m(X x) {
		
		System.out.println( "je suis m(X) de B"); 
	} 
	
void m (Y y) {
		
		System.out.println( "je suis m(Y) de B"); 
	}
	
void m (E e) {
	
	System.out.println( "je suis m(E) de B"); 
}
	
   void m(X x, Y y) {
		
		System.out.println( "je suis m(X,Y) de B"); 
	} 
	
	
	
	
	 void mb (Y y) {
		   
		   System.out.println( "je suis mb de B");
	   }
	 

	 
public B m(X x, Y y, Z z) {
	System.out.println( "je suis 'A m(X x, Y y, Z z)' de A"); 
	return new B(); 
		 
	 }	




/*
 // Erreur de redéfinition de m(X x, Y y, Z z) : Retour type qui ne spécialise pas A 
H m(X x, Y y, Z z) {
	 System.out.println( "je suis 'A m(X x, Y y, Z z)' de A"); 
	 return new H(); 
	 
}
*/


}
