package interfaces;

import java.lang.*;
import classes.*;

public interface ITransactions
{
	public abstract void withdraw(double amount);
	void deposit(double amount);
	void transfer(Account a, double amount);
}