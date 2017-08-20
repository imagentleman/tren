let cards = [
  "rojo.html",
  "sticky-header.html",
  "decrypt.html",
  "contribute.html"
];

let component = ReasonReact.statelessComponent "Card";

let make ::card ::className="card" ::onClick _children => {
  {
    ...component,
    render: fun {state, update} => {
      <div className=(className) onClick=(fun _ => onClick ())>
        <div className="card-bar">
          <button className="card-bar-toggle" />
        </div>

        <div className="card-content">
          <iframe src=( card ) />
        </div>
      </div>
    }
  }
};
