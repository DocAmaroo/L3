package ex2;

import java.lang.reflect.*;
import java.util.Scanner;

public class FabriquePersonnage {

	public FabriquePersonnage(){}
	
	
	public Personnage makePersonnage(String className) throws Exception{
		
		@SuppressWarnings("unchecked")
		Class<? extends Personnage> cls = (Class<? extends Personnage>) Class.forName(className);
		Constructor<?> cst = cls.getConstructor();
		Object np = cst.newInstance();
		return (Personnage) np;
	}

	public void setAttribut(Personnage p) throws Exception{
		// On récupère la classe
		Class c = p.getClass();
		
		// On récupère la liste des attributs de la classe
		Field[] field = c.getFields();
		
		
		Scanner scan = new Scanner(System.in);
		
		for (Field f : field) {
			
			System.out.println("Attribut : " + f.getName() + " -> " + f.getType());
			String value = scan.nextLine();
			
			switch (f.getType().getName()) {
			case "boolean":
				f.set(p, Boolean.valueOf(value));
				break;
			case "int":
				f.set(p, Integer.parseInt(value));
				break;
			default:
				f.set(p, value);
				break;
			}
		}
		
		System.out.println(p);
	}
	
}
