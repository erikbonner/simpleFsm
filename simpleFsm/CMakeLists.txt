set (libSimpleFsm_SRCS
  fsm.cpp  
  state.cpp
  transition.cpp
  bindablestate.h
  fsm.h
  ifsm.h
  istate.h
  itransition.h
  nullstate.h
  state.h
  terminationstate.h
  transition.h
)

add_library (libSimpleFsm ${libSimpleFsm_SRCS})

