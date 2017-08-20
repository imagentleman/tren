type state = {
  currentCard: string,
  cards: list string
};

let component = ReasonReact.statefulComponent "App";

let activate card _event {ReasonReact.state} =>
  ReasonReact.Update {...state, currentCard: card};

let deactivate event {ReasonReact.state} => {
  ReactEventRe.Mouse.preventDefault event;
  ReasonReact.Update {...state, currentCard: ""};
};

let checkKey event {ReasonReact.state} => {
  if (ReactEventRe.Keyboard.keyCode event === 27) {
    ReactEventRe.Keyboard.preventDefault event;
    ReasonReact.Update {...state, currentCard: ""};
  } else {
    ReasonReact.NoUpdate;
  }
};

let checkClick event {ReasonReact.state} => {
  ReactEventRe.Mouse.preventDefault event;
  let activeCard = (ReactDOMRe.domElementToObj (ReactEventRe.Mouse.target event))##closest ".card";

  if (activeCard) {
    ReasonReact.NoUpdate;
  } else {
    ReasonReact.Update {...state, currentCard: ""};
  }
};

let make _children => {
  {
    ...component,
    initialState: fun () => {
      {
        currentCard: "",
        cards: Card.cards
      }
    },
    render: fun {state, update} => {
      let cardElements = List.map (
        fun card => {
          let className = card === state.currentCard ? "card active" : "card";

          <Card
            key=(card)
            card
            className
            onClick=(update (activate card))
          />
        }
      ) state.cards;
      <div className="app" onKeyUp=(update checkKey) onClick=(update checkClick) tabIndex=0>
        <div>
          <a className="app-logo"
             href=""
             onClick=(update deactivate)> (ReasonReact.stringToElement "rC") </a>
        </div>

        <div className="tren">
          (ReasonReact.arrayToElement (Array.of_list cardElements))
        </div>
      </div>
    }
  }
};
