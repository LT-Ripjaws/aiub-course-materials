package Interfaces;
import java.lang.*;
import Classes.*;

public interface IAccountOperation
{
	public abstract void addAccount(Account a);
	void removeAccount(Account a);
	void showAllAccounts();
}