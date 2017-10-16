open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style [fontSize 18.];
  let flatten = flatten;
  let null = style [];
};

let component = ReasonReact.statelessComponent "CustomText";

let make ::style=? children => {
  ...component,
  render: fun _self => {
    let dynamicStyle =
      switch style {
      | Some propStyle => propStyle
      | None => Style.null
      };
    let stringArrayJoin lines => Array.fold_left (fun result line => result ^ line) "" lines;
    <Text style=(Style.flatten [|Style.container, dynamicStyle|])>
      (ReasonReact.stringToElement (stringArrayJoin children))
    </Text>
  }
};