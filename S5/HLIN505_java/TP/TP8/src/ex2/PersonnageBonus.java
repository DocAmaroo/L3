package ex2;

public class PersonnageBonus extends Personnage{
	
	private static int step = 10;

	public PersonnageBonus(){};
	
	public PersonnageBonus(String nom, int pv, int points){
		super(nom, pv, points);
	}

	@Override
	public void setPoints(int pv){
		if ( this.getPoints()%step == 0 ){
			setPv(this.getPv() + 1);
		}
	}

	@Override
	public String toString() {
		return "PersonnageBonus";
	}
	
	
	
}
