package test;

public class A {
	void m(X x) {
		
		System.out.println( "je suis m(X) de A"); 
	} 
	
	void m (Y y) {
		
		System.out.println( "je suis m(Y) de A"); 
	}
	
   void m (Z z) {
		
		System.out.println( "je suis m(Z) de A"); 
	}
	
   void m(X x, Y y) {
		
		System.out.println( "je suis m(X, Y) de A"); 
	} 
   
   void ma (X x) {
	   
	   System.out.println( "je suis ma de A");
   }

  void m(F f) {
	  System.out.println( "je suis m(F) de A");
	  
  }
	  
public A m(X x, Y y, Z z) {
	 System.out.println( "je suis 'A m(X x, Y y, Z z)' de A"); 
	 return new A(); 
	 
 }
  

public static void main (String[] param) {
	
	A a = new A(); 
	B b = new B();
	A ba = new B(); 
	X x = new X(); 
	Y y = new Y(); 
	X xy = new Y();
	Z z = new Z();
	Y yz = new Z(); 
	E e = new E(); 
	X xe = new E();
	F f = new F(); 
	G g = new G(); 
	X gx = new G();  
	F gf = new G(); 
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
	// 2) dans A : choix de m(X) et non pas m(Y) car matchning exact des paramètres car x est de type statique X
	// 3) a est de type dynamique A (= type statique), donc appliquer m(X) de A
	
	a.m(x); /* 4) résultat : je suis m(X) de A */
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
	// 2) dans A : choix de m(Y) et non pas m(X) car matchning exact des paramètres car y est de type statique Y
	// 3) a est de type dynamique A (= type statique), donc appliquer m(Y) de A
	a.m(y); /* 4) résultat : je suis m(Y) de A */
	
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
		// 2) dans A : choix de m(X) et non pas m(Y) car matchning exact des paramètres car xy est de type statique X
		// 3) a est de type dynamique A (= type statique), donc appliquer m(X) de A
	a.m(xy); /* 4) résultat : je suis m(X) de A */
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
	// 2) dans A : choix de ma(X) : pas d'autres méthodes avec le même nom
	// 3) a est de type dynamique A (= type statique), donc appliquer ma(X) de A
	
	a.ma(x); /* 4) résultat : je suis ma(X) de A */
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
	// 2) dans A : choix de ma(X) : pas d'autres méthodes avec le même nom, y est de type statique Y et Y est un sous type de X
		// 3) a est de type dynamique A (= type statique), donc appliquer ma(X) de A
	
	a.ma(y);/* 4) résultat : je suis ma(X) de A */
	
	
	// 1) a est de type statique A alors chercher la méthode dans la classe A 
	// 2) dans A : choix de ma(X) : pas d'autres méthodes avec le même nom et xy et de type statique X 
	// 3) a est de type dynamique A (= type statique), donc appliquer ma(X) de A
	
	a.ma(xy);/* 4) résultat : je suis ma(X) de A */
	
	// erreur "a" et de type statique A et mb() n'est pas défni dans le type statique A
	//a.mb(x); 
	
	// erreur "a" et de type statique A et mb() n'est pas défni dans le type statique A
	//a.mb(y); 
	
	// erreur "a" et de type statique A et mb() n'est pas défni dans le type statique A
	//a.mb(xy);
	
	// 1) b est de type statique B et X et de type statique X alors recherche de m(X) dans B
	// 2) Le type dynamique de b est B alors application de m(X) de B
	
	b.m(x); /* 4) résultat : je suis m(X) de B */
	b.m(y); /* 4) résultat : je suis m(Y) de B */
	
	// je cherche dans B une méthode m avec un seul paramètre de type X 
	// cette méthode existe et elle est définie dans B m(X) de B 
	b.m(xy); /* 4) résultat : je suis m(X) de B */
	
	// je cherche dans B une méthode ma() avec un seul paramètre de type X 
	// cette méthode existe et elle est héritée de de A ma(X) de A
	b.ma(x); /* 4) résultat : je suis ma(X) de A */
	
	// je cherche dans B une méthode ma avec un seul paramètre de type Y
	// cette méthode n'existe pas exactement avec le paramètre de type Y 
	// une méthode de type de paramètre X (super typpe de Y) existe ma(X) de A
	
	b.ma(y);/* 4) résultat : je suis ma(X) de A */
	
	// je cherche dans B une méthode ma avec un seul paramètre de type X 
	// cette méthode existe et elle est héritée de de A ma(X) de A
	 
	b.ma(xy); /* 4) résultat : je suis ma(X) de A */
	
	// erreur car x est de type statique X
	// b.mb(x); 
	
	// mb de B
	b.mb(y); /* 4) résultat : je suis mb de B */
	
	// erreur car xy est de type statique X
	//b.mb(xy);
	
	// je cherche dans B une méthode m avec un type statique Z 
	// cette méthode existe car héritée de A m(Z) de A
	b.m(z); /* 4) résultat : je suis m(Z) de A */
	
	//Je cherche dans B une méthode avec un paramètre de type E
	
	b.m(e);/* 4) résultat : je suis m(E) de B */

	// Je cherche dans A (qui est le type statique de ba) une méthode m(X)
	// elle existe, j'applique la liaison dynamique car cette méthode est redéfinie dans B (type dynamique de ba)
	
	ba.m(x);/* 4) résultat : je suis m(X) de B */
	ba.m(y); /* 4) résultat : je suis m(Y) de B */
	
	// je cherche dans A une méthode m(X), j'applique la liason dynamique
	
	ba.m(xy); /* 4) résultat : je suis m(X) de B */
	
	ba.ma(x);/* 4) résultat : je suis ma(X) de A */
	ba.ma(y);/* 4) résultat : je suis ma(X) de A */
	ba.ma(xy);/* 4) résultat : je suis ma(X) de A */
	
	
	// je cherche dans A une méthode m(Z), existe dans A et non redéfinie dans B 
	
	ba.m(z);/* 4) résultat : je suis m(Z) de A */
	
	// je cherche m(E) dans A, existe mais le paramètre est générique X ou Y  
	// donc m(X) et m(Y) mais choix de celui le plus spécialisée : m(Y)
	// application de la liaison dynamique donc m(Y) de B
	System.out.println("ba.m(e)");
	ba.m(e);/* 4) résultat : je suis ma(Y) de B */
	
	// Je cherche une méthode m(G) dans A, pas cette méthode dans A mais m(F) est dans A et F est un super type de G
	// Pas de réféfinition de M(F) dans B donc résultat m(F) de A
	ba.m(g);
	
	//erreur 
	//ba.mb(); 
	
	// recherche de m(F) dans A OK, m(f) de A
	ba.m(f); /* 4) résultat : je suis m(F) de A */
	
	
	// erreur "ba" et de type statique A et mb() n'est pas défni dans le type statique A
	//ba.mb(x); 
	// erreur "ba" et de type statique A et mb() n'est pas défni dans le type statique A
	//ba.mb(y);
	// erreur "ba" et de type statique A et mb() n'est pas défni dans le type statique A
	//ba.mb(xy);
	
	
	
	
	
}

}