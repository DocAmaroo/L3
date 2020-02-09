package Exercice1_Interface;

import java.lang.annotation.Annotation;
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;


enum TypeTache {ecrire, ameliorer, refactoriser, tester}

@Target(ElementType.METHOD )
public @interface ToDo {
	
	TypeTache type(); 
	int numeroVersion(); 
	double duree();  
}
