package com.example.androidake;

public class MutualAuthenticateChip {
	
	public boolean initiated = false;
	static {
		System.loadLibrary("nativecryptowrapper");
	}
	
	public native void prepare_MAC_CPP();

	public native byte[] get_ephemeralkey_CPP();

	public native void set_ephemeralkey_from_party_CPP(byte [] ephemeralKey);
	
	public native void prepare_encryption_CPP(boolean initiated);
	
	public native byte[] get_encrypt_cert_and_R_CPP();
	
	public native void set_encryption_from_party_CPP( byte [] encryption );
	
	public native boolean verif_certificate_CPP();
	
	public native void compute_session_key_CPP();
	
	public native byte[] get_session_key_CPP();
	
	public void set_initializator(boolean init){
		this.initiated = init;
	}
	
	public void prepare_keys_and_cert(){
		prepare_MAC_CPP();
	}
	
	public byte[] return_ephemeralkey(){
		return get_ephemeralkey_CPP();
	}
	
	public void set_ephemeralkey_from_party(byte [] ephemeralKey){
		set_ephemeralkey_from_party_CPP(ephemeralKey);
	}
	
	public byte[] get_encrypt_cert_and_R(){
		return get_encrypt_cert_and_R_CPP();
	}
	
	public void prepare_encryption(boolean initiated){
		prepare_encryption_CPP(this.initiated);
	}
	
	
	public void set_encryption_from_party( byte [] encryption ){
		set_encryption_from_party_CPP(encryption);
	}
	
	public boolean verif_certificate(){
		return verif_certificate_CPP();
	}
	
	public void compute_session_key(){
		compute_session_key_CPP();
	}
	
	public void get_session_key(){
		byte[] sk = get_session_key_CPP();
	}
}
