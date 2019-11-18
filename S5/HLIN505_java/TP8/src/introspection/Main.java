package introspection;

import java.lang.reflect.Method;
import java.util.ArrayList;

public class Main {
	
	public static void method(Class c){
		Method[] listmeth = c.getMethods();
		for ( Method m : listmeth ){
			String m_name = m.getName();
			Class m_rType = m.getReturnType();
			Class[] m_pType = m.getParameterTypes();
			
			System.out.print(" "+m_rType.getName()+" "+m_name + "(");
			for (int j=0; j<m_pType.length; j++){ System.out.print(""+m_pType[j].getName());}
			System.out.println(")");
		}
	}
	
	public static void main(String[] args){
		
		//list d'entier
		ArrayList<Object> list = new ArrayList<Object>();
		list.add(1);
		list.add("aloha");
		list.add(true);
		
		Class c = list.get(0).getClass();
		method(c);
	}

	

		
}
