package classesInternes;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Personne {

	private final String dateNaissance; // au format JJ/MM/AAAA

	
	public Personne(String dateNaissance) {
		super();
		this.dateNaissance = dateNaissance;
	}


	private boolean validateDate(){
		class Date{
			int j, m, a;
			Date(String s){
				if (s.matches("[0-3][0-9]/[0-1][0-9]/[1-2][0-9][0-9][0-9]")){
					System.out.println("ça matche");
					j=Integer.parseInt(s.substring(0, 2));
					m=Integer.parseInt(s.substring(3,5));
					a=Integer.parseInt(s.substring(6,10));
				} else {
					System.out.println("ça matche pas");
					j=-1;
					m=-1;
					a=-1;
				}
			}
			int getAnnee(){
				return a;
			}
			
			boolean verification(){
				return j>0 &&j<31 &&m>0 &&m<13 && a>1900 && a<= new GregorianCalendar().get(Calendar.YEAR);
			}
			
			void print(){
				System.out.println(j+"/"+m+"/"+a);
			}
		}
		Date d=new Date(dateNaissance);
		d.print();
		return (d.getAnnee()!=-1 && d.verification());
	}
	
	
	public static void main(String[] args){
		Personne p=new Personne("10/12/2017");
		System.out.println(p.validateDate());
		
		System.out.println(new GregorianCalendar().get(Calendar.YEAR));
	}
}
