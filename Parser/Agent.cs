using System;

public enum Action
{
	Clap,
	Dance,
	Stop
}
public class Agent
{
	private int AgentID;
	private float velocity;
	private Action action;

	public Agent(int ID)
	{
		AgentID = ID;
		velocity = 1.0;
		action = Action.Stop;

	}

	public int getID()
    {
		return AgentID;
    }

	public float getVelicity()
    {
		return velocity;
    }

	public Action getAction()
    {
		return action;
    }

	public void setVelicity(float v)
	{
		velocity = v;
	}

	public void getAction(Action a)
	{
		action = a;
	}
}
