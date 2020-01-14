package tpTest.visites.toTest;

import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.Collection;

import org.junit.Before;
import org.junit.Test;
import org.junit.runners.Parameterized.Parameters;

public class TestEtape {
	
	Etape etape;
	String nom, rue;
	int dureeVisite;
	NatureEtape type;
	
	@Parameters
	public static Collection data(){
		return Arrays.asList(new Object[][]{
			{"La Louvrette", "Jean Michel Crapaud", 3, NatureEtape.musee},
			{"NATATION", "LA PISCINE MUNICIPAL DANS LAQUELLE TU PIZE", 2, NatureEtape.lieuInteretSansVisite},
			{"Masse à chaussettes", "US ADRESS", 1, NatureEtape.visiteMonument},
			{"Mimi Matty <3", "trop petit pour que ça existe", 2, NatureEtape.visiteJardin}
		});
	}
	
	public TestEtape(String nom, String rue, int dureeVisite, NatureEtape type){
		this.nom = nom;
		this.rue = rue;
		this.dureeVisite = dureeVisite;
		this.type = type;
	}
	
	@Before
	public void setUp() throws Exception {
		etape = new Etape(nom, rue, dureeVisite, type);
	}
	
	@Test
	public void TestConstructor(){
		assertEquals(etape.getNom(), nom);
		assertEquals(etape.getRue(), rue);
		assertEquals(etape.getDureeVisite(), dureeVisite);
		assertEquals(etape.getType(), type);
	}
	
}
