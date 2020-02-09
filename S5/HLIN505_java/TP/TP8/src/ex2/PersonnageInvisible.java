package ex2;

public class PersonnageInvisible extends Personnage{
	
	public boolean invisible;
	public int timerInvisible;
	public int cooldown;
	
	public PersonnageInvisible(){};
		
	public PersonnageInvisible(String nom, int pv, int points, boolean invisible, int timerInvisible, int cooldown){
		super(nom, pv, points);
		this.invisible = invisible;
		this.timerInvisible = timerInvisible;
		this.cooldown = cooldown;
	}

	public boolean getInvisible(){
		return invisible;
	}

	public void setInvisible(){
		if (invisible){
			invisible = false;
		}
		else{
			invisible = true;
		}
	}
	
	public int getTimerInvisible() {
		return timerInvisible;
	}

	public void setTimerInvisible(int timerInvisible) {
		this.timerInvisible = timerInvisible;
	}

	public int getCooldown() {
		return cooldown;
	}

	public void setCooldown(int cooldown) {
		this.cooldown = cooldown;
	}

	@Override
	public String toString() {
		return super.toString() + "\ninvisible = " + invisible + "\ntimerInvisible = " + timerInvisible + "\ncooldown = " + cooldown;
	}
	
	
}
