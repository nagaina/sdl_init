#ifndef LE_SDL_EVENT_HPP
#define LE_SDL_EVENT_HPP

class le_event
{
public:
	void porcess_events();

	static le_event& get();

private:

	le_event() : m_quit(false) {}

	le_event(const le_event&) = delete;
	le_event& operator=(const le_event&) = delete;

private:
	static le_event* m_instance;

	bool m_quit;
};
#endif
